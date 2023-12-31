# ngx_ip2region

## build

```shell
$ mkdir -p workspace
$ cd workspace
$ wget https://nginx.org/download/nginx-1.24.0.tar.gz
$ tar -zxf nginx-1.24.0.tar.gz && rm -rf nginx-1.24.0.tar.gz
$ git clone https://github.com/yunsur/ngx_ip2region.git
$ git clone https://github.com/lionsoul2014/ip2region.git
$ cd ip2region/binding/c
$ make xdb_searcher_lib
$ cd ../../../nginx-1.24.0
$ ./configure                                                            \
    --add-module=$(PWD)/../ngx_ip2region                                 \
    --with-cc-opt="-I $(PWD)/../ip2region/binding/c/build/include"       \
    --with-ld-opt="-L$(PWD)/../ip2region/binding/c/build/lib"
$ make
$ make install
```

## nginx conf

> Syntax:  `ip2region_db xdb_file_path [cache_policy Optional]`;
> Context: http

cache_policy: `file` or `vectorIndex` or `content`, default: `content`

Edit `nginx.conf` add `ip2region_db` directive

```nginx
...
stream {

    log_format main escape=json '{'
                                '"remote_addr": "$remote_addr", '
                                '"region": "$ip2region", '
                                '}';

    access_log logs/access.log main;

    # set xdb file path
    ip2region_db ip2region.xdb;
    # ip2region_db ip2region.xdb vectorIndex;
    # ip2region_db ip2region.xdb file;
    # ip2region_db ip2region.xdb content;
}

```

Copy `ip2region.xdb` to `nginx/config` folder, then restart nginx, the `region` data stored in `ip2region` variable

nginx access log sample

```log
{"remote_addr": "127.0.0.1", "region": "0|0|0|内网IP|内网IP", "http_x_forwarded_for": ""}
{"remote_addr": "127.0.0.1", "region": "0|0|0|内网IP|内网IP", "http_x_forwarded_for": ""}

```

Made with ♥ by yunsur

Thanks ♥ Wu Jian Ping
