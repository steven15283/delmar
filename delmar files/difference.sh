#!/bin/bash
## illustrating difference between $* and $@
echo "Printing \$* "
for i in $*
do
        echo i is: $i
done

echo "Printing \$@ "
for i in "$@"
do
        echo i is: $i
done

