/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: rryqszq4                                                     |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#include "jsr_list.h"

jsr_list_t *
jsr_list_new(void)
{
    jsr_list_t *self = (jsr_list_t *)malloc(sizeof(jsr_list_t));
    return self;
}

void 
jsr_list_destroy(jsr_list_t **self_p)
{
    if (*self_p){
        jsr_list_t *self = *self_p;
        jsr_list_purge(self);
        free(self);
        *self_p = NULL;
    }
}

void *
jsr_list_first(jsr_list_t *self)
{
    self->cursor = self->head;
    if (self->cursor)
        return self->cursor->item;
    else
        return NULL;
}

void *
jsr_list_next(jsr_list_t *self)
{
    if (self->cursor)
        self->cursor = self->cursor->next;
    else
        self->cursor = self->head;

    if (self->cursor)
        return self->cursor->item;
    else
        return NULL;
}

void *
jsr_list_last(jsr_list_t *self)
{
    self->cursor = self->tail;
    if (self->cursor)
        return self->cursor->item;
    else
        return NULL;
}

void *jsr_list_head(jsr_list_t *self);
void *jsr_list_tail(jsr_list_t *self);
void *jsr_list_item(jsr_list_t *self);

int jsr_list_append(jsr_list_t *self, void *item);
int jsr_list_push(jsr_list_t *self, void *item);
void *jsr_list_pop(jsr_list_t *self);
void jsr_list_remove(jsr_list_t *self, void *item);

int jsr_list_exists(jsr_list_t *self, void *item);

jsr_list_t *jsr_list_dup(jsr_list_t *self);

void jsr_list_purge(jsr_list_t *self);

size_t jsr_list_size(jsr_list_t *self);

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */