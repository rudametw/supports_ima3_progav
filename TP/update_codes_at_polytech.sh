#!/bin/bash
echo DRY RUN
echo try polytech-lille.fr
rsync -avzhl --dry-run -e 'ssh -p 2222' --progress codes/ wrudamet@portier.polytech-lille.fr:~/public/IMA3/

echo try houplin:
rsync -avzhl --dry-run                --progress codes/ wrudamet@houplin.studserv.deule.net:~/public/IMA3/

echo Did nothing, run command without dry-run
