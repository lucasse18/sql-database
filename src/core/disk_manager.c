#include <stdlib.h>
#include <core/disk_manager.h>

struct DISK_BLOCK_ID {
  size_t id;
};

int dm_init(int dbsiz) {

}

int dm_block_write(void *data, const disk_block_id_t *block) {

}

int dm_block_read(void *out, const disk_block_id_t *block) {

}
