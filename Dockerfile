FROM ubuntu:18.02

RUN apt-get install python3.7

RUN python3 -m pip install numpy==1.21
RUN python3 -m pip install pandas==0.20.3
RUN python3 -m pip install tensortflow==1.13.1

RUN echo "Compilation Successful"
