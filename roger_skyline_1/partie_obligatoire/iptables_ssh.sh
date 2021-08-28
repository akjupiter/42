#!/bin/bash

sudo iptables -F
sudo iptables -X

sudo iptables -t filter -A INPUT -p TCP --dport 2020 -j ACCEPT
sudo iptables -t filter -A OUTPUT -p TCP --sport 2020 -j ACCEPT

sudo iptables -t filter -A OUTPUT -o lo -j ACCEPT
sudo iptables -t filter -A INPUT -i lo -j ACCEPT

sudo iptables -A INPUT -i ens33 -p icmp -j ACCEPT
sudo iptables -A OUTPUT -o ens33 -p icmp -j ACCEPT

sudo iptables -t filter -A OUTPUT -p udp --dport 53 -m conntrack --ctstate NEW         -j ACCEPT
sudo iptables -t filter -A INPUT  -p udp --sport 53 -m conntrack --ctstate ESTABLISHED -j ACCEPT

sudo iptables -t filter -A OUTPUT -p tcp -m multiport\
 --dports 80,443,8000 -m conntrack --ctstate\
 NEW,ESTABLISHED -j ACCEPT
 
sudo iptables -t filter -A INPUT -p tcp -m multiport\
 --sports 80,443,8000 -m conntrack --ctstate\
 ESTABLISHED -j ACCEPT

sudo iptables -t filter -A INPUT -j DROP
sudo iptables -t filter -A OUTPUT -j DROP
sudo iptables -t filter -A FORWARD -j DROP
