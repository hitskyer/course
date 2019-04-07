function timediff() 
{
	# time format:date +"%s.%N", such as 1502758855.907197692
    start_time=$1
    end_time=$2
    
    start_s=${start_time%.*}
    start_nanos=${start_time#*.}
    end_s=${end_time%.*}
    end_nanos=${end_time#*.}
    
    # end_nanos > start_nanos? 
    # Another way, the time part may start with 0, which means
    # it will be regarded as oct format, use "10#" to ensure
    # calculateing with decimal
    if [ "$end_nanos" -lt "$start_nanos" ];then
        end_s=$(( 10#$end_s - 1 ))
        end_nanos=$(( 10#$end_nanos + 10**9 ))
    fi
    
	# get timediff
    time=$(( 10#$end_s - 10#$start_s )).$(( (10#$end_nanos - 10#$start_nanos)/10**6 ))
    avgtime=`echo "sclae=4; $time/$n" | bc -l`
    echo $avgtime
}

starttime=`date +'%s.%N'`

i=0
n=5
while [ $i -lt 5 ] #循环，把两个5改成想要运行的次数
do
    ./1 100  #需要运行的程序
    wait
    let i=i+1
done
wait # 等待执行完成 即可
endtime=`date +'%s.%N'`

echo "程序平均运行时间： "  
timediff $starttime $endtime #比较开始和结束时间的差
echo " s"
exit 0