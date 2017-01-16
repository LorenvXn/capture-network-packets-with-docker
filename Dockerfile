FROM ubuntu:14.04
RUN apt-get update
RUN  apt-get upgrade -y
RUN  apt-get -y install gcc mono-mcs
RUN  apt-get -y install libpcap0.8-dev
COPY . /home
WORKDIR /home
RUN  gcc handle.c -o handle -lpcap
