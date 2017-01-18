#include<stdio.h>
#include<pcap.h>

int main(int argc, char **argv){
        char *device;
        char err_buffer[PCAP_ERRBUF_SIZE];
        char *pcap_lookupdev(char *err_buffer);

        device = pcap_lookupdev(err_buffer);
        if(device==NULL){
                printf("not finding device: %s\n", err_buffer);
                return 1;
        }

        printf("network devices found: %s\n", device);
        return 0;
}

