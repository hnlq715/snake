#!/usr/bin/perl -w

open(STDOUT,">log.txt") or
  die "can't open log.txt";
system("./mySnake.exe");

