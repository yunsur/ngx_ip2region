/*
 * Copyright (C) Wu Jian Ping
 * Copyright (C) yunsur
 */

#ifndef _NGX_STREAM_IP2REGION_MODULE_H_INCLUDED_
#define _NGX_STREAM_IP2REGION_MODULE_H_INCLUDED_

#include <xdb_searcher.h>

typedef struct {
    xdb_searcher_t       searcher;
    xdb_vector_index_t  *v_index;
    xdb_content_t       *c_buffer;
} ip2region_searcher_t;

typedef struct {
    ip2region_searcher_t *ip2region_searcher;
} ngx_stream_ip2region_conf_t;

#endif /* _NGX_STREAM_IP2REGION_MODULE_H_INCLUDED_ */
