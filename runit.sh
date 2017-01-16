#!/bin/bash

 docker build -t sniffit1 .


echo "###########Sniffing interface from container################ "
echo
 docker run -ti sniffit1 ./handle /bin/bash 
