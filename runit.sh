#!/bin/bash

 docker build -t sniffit1 .


echo "###########Sniffing interface from container################ "
echo
 while sleep 1; do docker run -ti -p 8080:8080 sniffit1 ./handle /bin/bash ; done;
