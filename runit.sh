#!/bin/bash

 docker build -t sniffit1 .

echo
echo "###########Sniffing interface from container################ "
echo
## while sleep 1; do docker run -ti -p 8080:8080 sniffit1 ./blablascript /bin/bash ; done; #where is mah mind?!...
docker run -ti sniffit1 ./find_device /bin/bash
echo
echo "############Packet capture length############################"
echo
docker run -ti sniffit1 ./packet_length /bin/bash
 
