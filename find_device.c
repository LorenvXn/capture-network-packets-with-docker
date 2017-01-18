#include<stdio.h>
#include<pcap.h>

int main(int argc, char **argv){
        char *device;
        char error_buffer[PCAP_ERRBUF_SIZE];
        char *pcap_lookupdev(char *error_buffer);

        device = pcap_lookupdev(error_buffer);
        if(device==NULL){
                printf("not finding device: %s\n", error_buffer);
                return 1;
        }

        printf("network devices found: %s\n", device);
        return 0;
}

