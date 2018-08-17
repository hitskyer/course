

starttime=`date +'%Y-%m-%d %H:%M:%S'`

i=0
n=2
while [ $i -lt 2 ] 
do
    ./a.out big quicksort1 &
    let i=i+1
done
wait # 等待执行完成 即可
endtime=`date +'%Y-%m-%d %H:%M:%S'`

start_seconds=$(date --date="$starttime" +%s)
end_seconds=$(date --date="$endtime" +%s)
let time=end_seconds-start_seconds
let avgtime=time/n
echo "程序平均运行时间： $avgtime s"

exit 0
