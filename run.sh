#!/bin/bash

# 创建日志文件夹 log/ 如果不存在
mkdir -p log

# 循环从 0 到 49
#for i in {0..99}
for i in {0..99}
do
  # 使用nohup命令在后台运行程序，并将输出重定向到日志文件
  #nohup ./generate_samples8_herwig -i $i > log/output_$i.log 2>&1 &
  nohup ./generate_sample_CMSMC -i $i > log/output_$i.log 2>&1 &

  echo "Started process with -i $i, output to log/output_$i.log"
done