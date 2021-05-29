#include <stdio.h>                                                              
#include <fcntl.h>                                                              
#include <sys/mman.h>                                                           
#include <stdint.h>                                                             
 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

// GPX2 Base Address 0x1100_0000
// GPX2 Control Address -> GPX2_Base Address + 0x0C40
// GPX2 Data Address -> GPX2_Base Address + 0x0C44
#define GPIO_BASEADDRESS 0x11000000
#define WHEELBUTTON_OFFSET   0x0c44     
#define FPGA_BASEADDRESS 0x05000000            
#define PIEZO_OFFSET     0x50     

 
int main(void) {
   int memDev;
   uint32_t *gpio, *wheelButton_addr;
   unsigned short *fpga, *piezo_addr;
   int pagesize;
   int sw1, sw2 ;                                                          

   if ((memDev = open ("/dev/mem", O_RDWR | O_SYNC) ) < 0) {                   
       printf("Unable to open /dev/mem\n");                            
       return -1;                                                      
   }                                                                       
   pagesize = getpagesize();
   gpio = mmap(NULL, pagesize, PROT_READ|PROT_WRITE, MAP_SHARED, memDev, GPIO_BASEADDRESS);    
   if (gpio < 0){                                                          
       printf("Mmap gpio failed.\n");                                       
       return -1;                                                      
   }                                                                       
   wheelButton_addr = gpio + WHEELBUTTON_OFFSET/sizeof(uint32_t);

   fpga = mmap(NULL, pagesize, PROT_READ|PROT_WRITE, MAP_SHARED, memDev, FPGA_BASEADDRESS);    
   if (fpga < 0){                                                          
       printf("Mmap fpga failed.\n");                                       
       return -1;                                                      
   }                                                                       
   piezo_addr = fpga + PIEZO_OFFSET/sizeof(unsigned short);
 
	printf("201701095 HyunDo Kim: Please push the button !\n");
	while (1) {
	   // SW1 GPIO -> GPX2_3 , SW2 GPIO -> GPX2_5
	   sw1 = ((*(unsigned int *) wheelButton_addr) >> 3)&0x1;
	   sw2 = ((*(unsigned int *) wheelButton_addr) >> 5)&0x1;
       if (sw1 == 1 && sw2 == 0){
           printf("201701095 HyunDo Kim: SW1=%d, SW2=%d\n", sw1, sw2);
			*piezo_addr = 0x14;
			usleep(500000);
			*piezo_addr = 0x13;
			usleep(500000);
			*piezo_addr = 0x12;
			usleep(500000);
			*piezo_addr = 0;
       }
       else if(sw1 == 0 && sw2 == 1){
           printf("201701095 HyunDo Kim: SW1=%d, SW2=%d\n", sw1, sw2);
			*piezo_addr = 0x14;
			usleep(500000);
			*piezo_addr = 0x16;
			usleep(500000);
			*piezo_addr = 0x21;
			usleep(500000);
			*piezo_addr = 0;
       }
	} // end of while

	munmap(&fpga, pagesize);
	munmap(&gpio, pagesize);
	close(memDev);
	return 0;
}
