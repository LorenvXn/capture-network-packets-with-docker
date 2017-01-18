FROM ubuntu:14.04
RUN apt-get update
RUN  apt-get upgrade -y
RUN  apt-get -y install gcc mono-mcs
RUN  apt-get -y install libpcap0.8-dev
COPY . /home
WORKDIR /home
RUN  gcc find_device.c -o find_device -lpcap
RUN  gcc packet_length.c -o packet_length -lpcap
