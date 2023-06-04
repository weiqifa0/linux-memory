#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/gfp.h>

#define PAGE_ORDER 1

struct page *page;
unsigned long int virt_addr;
#define LOG_TAG "PAGE_TEST| "

static int __init hello_init(void)
{
	page = alloc_pages(GFP_KERNEL, PAGE_ORDER);
	printk(LOG_TAG "page frame no: %lx\n", page_to_pfn(page));
	printk(LOG_TAG "physical addr: %llx\n", page_to_phys(page));
	virt_addr = (unsigned long long int)page_address(page);
	printk(LOG_TAG "virtual addr: %lx\n", virt_addr);
	return 0;
}

static void __exit hello_exit(void)
{
	free_pages(virt_addr, PAGE_ORDER);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("329410527@qq.com");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("page api test");
