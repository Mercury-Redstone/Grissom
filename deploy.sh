#!/bin/bash
cat *.sql | ./database-import

./add-user Administrator root@localhost 00000000 SYSTEM SYSTEM 0000 M
./add-user Nobody nobody@localhost 00000000 SYSTEM SYSTEM 0000 M