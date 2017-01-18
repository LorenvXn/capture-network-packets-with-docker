#include<stdio.h>
#include<time.h>
#include<pcap.h>
#include<netinet/in.h>
#include<netinet/if_ether.h>

void packet_handler(
        u_char *args,
        const struct pcap_pkthdr *header,
        const u_char *packet
);

void packet_info(const u_char *packet, struct pcap_pkthdr packet_header);


int main(int argc, char *argv[]) {
    char *device;
    char err_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeout_limit = 10000; 

    device = pcap_lookupdev(err_buffer);
    if (device == NULL) {
        printf("Error finding device: %s\n", err_buffer);
        return 1;
    }

    handle = pcap_open_live(
            device,
            BUFSIZ,
            0,
            timeout_limit,
            err_buffer
        );
    if (handle == NULL) {
         fprintf(stderr, "Cannot open device %s: %s\n", device, err_buffer);
         return 2;
     }

    pcap_loop(handle, 0, packet_handler, NULL);

    return 0;
}

void packet_handler(
    u_char *args,
    const struct pcap_pkthdr *packet_header,
    const u_char *packet_body
)
{
    packet_info(packet_body, *packet_header);
    return;
}

void packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {
    printf("Packet capture length: %d\n", packet_header.caplen);
    printf("Packet total length %d\n", packet_header.len);
}
