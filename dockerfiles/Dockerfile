# vim:set ft=dockerfile:
FROM debian:buster-slim
RUN groupadd -r -g 1337 user
RUN useradd -r -g user -u 1337 user
RUN groupadd -r -g 2020 flag
RUN useradd -r -g user -u 2020 flag
RUN apt-get update
RUN apt-get install -y openssh-server less gcc
RUN mkdir -p /home/user/.ssh
COPY flag /home/flag/
RUN chown -R flag:flag /home/flag
RUN chmod -R 770 /home/flag/
COPY read_me /home/user/
RUN chown flag:flag /home/user/read_me
RUN chmod 600 /home/user/read_me
COPY script.c /tmp/
RUN cd /tmp && gcc script.c && rm script.c && mv /tmp/a.out /home/user/read
RUN chown flag:flag /home/user/read
RUN chmod ug+s /home/user/read
COPY authorized_keys /home/user/.ssh/
RUN chown -R user:user /home/user/.ssh/
RUN chmod 644 /home/user/.ssh/authorized_keys
COPY sshd_config /etc/ssh/
RUN service ssh start
EXPOSE 22
CMD ["/usr/sbin/sshd","-D"]