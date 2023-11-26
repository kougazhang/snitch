#!/bin/bash

# dump_lost <log_file> <key words>
dump_lost()
{
    echo "====== $2 ======"
    awk "
        BEGIN {
            cnt=0
        };
        /$2/ {
            printf \"=== %d ===\\n\", ++cnt;
            print \$0;
            getline;
            while (\$2 != NULL) {
                print \$0;
                getline;
            };
            print \"\"
        }
        END {
            printf \"====== $2 Total: %d ======\\n\", cnt;
        };
    " $1
}

dump_lost valgrind.log "definitely lost" > 0.definitely_lost.log
dump_lost valgrind.log "indirectly lost" > 1.indirectly_lost.log
dump_lost valgrind.log "possibly lost" > 2.possibly_lost.log
dump_lost valgrind.log "still reachable" > 3.still_reachable.log
dump_lost valgrind.log "Invalid read" > 4.invalid_used.log
dump_lost valgrind.log "Invalid write" >> 4.invalid_used.log
dump_lost valgrind.log "Invalid free" >> 4.invalid_used.log
dump_lost valgrind.log "Conditional jump or move depends on uninitialised value" > 5.uninitialised_used.log
dump_lost valgrind.log "Syscall param write(buf) points to uninitialised byte" >> 5.uninitialised_used.log
dump_lost valgrind.log "Source and destination overlap in memcpy" > 6.overlap_used.log