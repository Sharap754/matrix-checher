FROM ubuntu:latest

RUN apt update && apt install -y libc6

COPY matrix-check.deb /tmp/

RUN dpkg -i /tmp/matrix-check.deb

RUN chmod +x /usr/bin/matrix_check

CMD ["/usr/bin/matrix_check"]
