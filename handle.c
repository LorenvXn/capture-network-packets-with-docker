#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[])
        {
         pcap_t *handle;
         char dev[] = "eth0";
         char errbuf[PCAP_ERRBUF_SIZE];
         struct bpf_program fp;
         char filter_exp[] = "port 8080";
         bpf_u_int32 mask;
         bpf_u_int32 net;
        struct pcap_pkthdr header;
                const u_char *packet;

         if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
                 fprintf(stderr, "Can't get netmask for device %s\n", dev);
                 net = 0;
                 mask = 0;
         }
         handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
         if (handle == NULL) {
                 fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
                 return(2);
         }
         if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
                 fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
                 return(2);
         }
         if (pcap_setfilter(handle, &fp) == -1) {
                 fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
                 return(2);
         }
        packet = pcap_next(handle, &header);
                printf("Packet length of %d from device %s \n", header.len, dev);
                pcap_close(handle);
                return(0);
}
