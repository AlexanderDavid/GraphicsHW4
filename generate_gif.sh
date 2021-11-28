#/bin/env sh

min=6
inc=-0.005
max=-1.50

frame=0
for i in `seq $min $inc $max`; do
    padded=$(printf %04d $frame)
    build/bin/subd initial_points $i 10 | python viewer.py "weight = $i iterations=10" "./gif/$padded.png"
    frame=$(echo "$frame + 1" | bc)
done
