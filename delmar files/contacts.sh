#!/bin/bash
## consult my contacts for args given

for x in "$@"   
    do grep -i "$x" ~/myContactList
done
