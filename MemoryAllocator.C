#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MEMORY_POOL_SIZE 1024 * 1024 // 1 MB

static char memory_pool[MEMORY_POOL_SIZE];
static size_t allocated_size = 0;

void* my_malloc(size_t size) {
    if (allocated_size + size > MEMORY_POOL_SIZE) {
        return NULL; // Not enough memory
    }
    void* ptr = memory_pool + allocated_size;
    allocated_size += size;
    return ptr;
}

void my_free(void* ptr) {
    // Custom free logic can be implemented here
    // For simplicity, this implementation does not free memory
}

int main() {
    void* ptr1 = my_malloc(100);
    void* ptr2 = my_malloc(200);
    
    printf("Allocated memory at: %p\n", ptr1);
    printf("Allocated memory at: %p\n", ptr2);
    
    my_free(ptr1);
    my_free(ptr2);
    
    return 0;
}
