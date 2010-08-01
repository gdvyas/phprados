#ifndef PHP_LIBRADOS_H
#define PHP_LIBRADOS_H

#define PHP_LIBRADOS_EXTNAME  "librados"
#define PHP_LIBRADOS_EXTVER   "0.9"

extern "C" {
#include "php.h"
#ifdef ZTS
#include "TSRM.h"
#endif
}

using namespace std;
#include "rados/librados.hpp"
using namespace librados;

typedef struct _php_rados_pool {
    pool_t pool;
} php_rados_pool;

#define PHP_RADOS_POOL_RES_NAME "RADOS Pool"

PHP_MINIT_FUNCTION(librados);

PHP_METHOD(Rados, __construct);
PHP_METHOD(Rados, initialize);

/* Pool methods */
PHP_METHOD(Rados, open_pool);
PHP_METHOD(Rados, close_pool);
PHP_METHOD(Rados, lookup_pool);
PHP_METHOD(Rados, create);

extern zend_module_entry librados_module_entry;
#define phpext_librados_ptr &librados_module_entry;

#endif
