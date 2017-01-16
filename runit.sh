#!/bin/bash

 docker build -t sniffit1 .


echo "###########Sniffing interface from container################ "
echo
while sleep 1 ; do  docker run -ti sniffit ./handle /bin/bash ;done
