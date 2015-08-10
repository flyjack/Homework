//将IP地址考虑为以每个8位的组合

//减少数据存储的方式，像base62encode, ip转换为数字

<?php

    $ip = "172.16.89.100";
    $arr = explode(".", $ip);

    $ip1 = intval($arr[0]) << 24;
    $ip2 = intval($arr[1]) << 16;
    $ip3 = intval($arr[2]) << 8;
    $ip4 = intval($arr[3]);

    $v = $ip1 | $ip2 | $ip3 | $ip4;
    echo $v . "\n";

    $v1 = $v >> 24 & 0xff;
    $v2 = $v >> 16 & 0xff;
    $v3 = $v >> 8 & 0xff;
    $v4 = $v & 0xff;

    echo $v1 . "\n";
    echo $v2 . "\n";
    echo $v3 . "\n";
    echo $v4 . "\n";
