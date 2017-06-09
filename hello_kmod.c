#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>

#define BUFFSIZE 8

struct cdev char_dev;
char kern_buff[BUFFSIZE+1] = "hakodate";

static int chardev_open(struct inode *inode, struct file *file){
		printk(KERN_INFO "Device Opended.\n");
		return 0;
}

static int chardev_close(struct inode *inode, struct file *file){
		printk(KERN_INFO "Device Closed.\n");
		return 0;
}

static ssize_t chardev_read(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < 8) {
				printk(KERN_INFO "count size smaller than 8\n");
				return -ENOSPC;
		}
		copy_to_user(buf, kern_buff, BUFFSIZE);
		return count;
}

static ssize_t chardev_write(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < 8) {
				printk(KERN_INFO "count size smaller than 8\n");
				return -ENOSPC;
		}
		copy_from_user(kern_buff, buf, BUFFSIZE);
		printk(KERN_INFO "write string = %s\n", kern_buff);
		return count;
}

static struct file_operations chardev_fops = {
        .owner = THIS_MODULE,
        .open = chardev_open,
        .read = chardev_read,
        .release = chardev_close,
        .write = chardev_write,
};

dev_t dev = MKDEV(240, 0);

static int __init hello_init(void)
{
		int err;
		register_chrdev_region(dev, 1, "hello");
		cdev_init(&char_dev, &chardev_fops);
		err = cdev_add(&char_dev, dev, 1);
		printk(KERN_INFO "init cdev.\n");
		printk(KERN_INFO "setup hakodate!\n");
		printk(KERN_INFO "Hello World\n");
		return 0;
}

static void __exit hello_exit(void)
{
		//delete chardevice
		cdev_del(&char_dev);

		//release chardev number
		unregister_chrdev_region(dev, 1);
		printk(KERN_INFO "Bey World\n");
		return;
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Yota Nagai");
