#include "lisp_site.h"
#include "defs.h"

lisp_site_prefix *lisp_site_prefix_init(lisp_addr_t *eid_prefix, uint32_t iid,
        int key_type, char *key, uint8_t more_specifics, uint8_t proxy_reply) {

    lisp_site_prefix *sp = NULL;
    sp = calloc(1, sizeof(lisp_site_prefix));
    if (!sp)
        return(NULL);
    sp->eid_prefix = eid_prefix;
    sp->iid = iid;
    sp->key_type = key_type;
    sp->key = strdup(key);
    sp->accept_more_specifics = more_specifics;
    sp->proxy_reply = proxy_reply;

    return(sp);
}

void lisp_site_prefix_del(lisp_site_prefix *sp) {
    if (!sp)
        return;
    if (sp->eid_prefix)
        lisp_addr_del(sp->eid_prefix);
    if (sp->key)
        free(sp->key);
}