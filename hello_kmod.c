#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>

#define BUFFSIZE 8
#define CHARSIZE 1

struct cdev char_dev_array[BUFFSIZE+1];
char kern_buff[BUFFSIZE+1] = "hakodate";

static int chardev_open(struct inode *inode, struct file *file){
		printk(KERN_INFO "Device Opended.\n");
		int minor = iminor(inode);
		file->private_data = (void *)minor;
		return 0;
}

static int chardev_close(struct inode *inode, struct file *file){
		printk(KERN_INFO "Device Closed.\n");
		return 0;
}

static ssize_t chardev_read(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}

		int minor = (int)file->private_data;
		if (minor != 0){
				int index = minor-1;
				copy_to_user(buf, &kern_buff[index], CHARSIZE);
		} else {
				copy_to_user(buf, kern_buff, BUFFSIZE);
		}
		return count;
}

static ssize_t chardev_write(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}

		int minor = (int)file->private_data;

		if (minor != 0){
				int index = minor-1;
				copy_from_user(&kern_buff[index], buf, CHARSIZE);
		} else {
				copy_from_user(kern_buff, buf, BUFFSIZE);
		}
		return count;
}

static struct file_operations chardev_fops = {
		.owner = THIS_MODULE,
		.open = chardev_open,
		.read = chardev_read,
		.release = chardev_close,
		.write = chardev_write,
};

dev_t dev_array[BUFFSIZE+1];

static int __init hello_init(void)
{
		int i = 0;
		//setup major minor number
		for (i = 0; i < BUFFSIZE+1; i++ ){
				dev_array[i] = MKDEV(240, i);
		}
		register_chrdev_region(dev_array[0], 9, "hello");
		for (i = 0; i < BUFFSIZE+1; i++ ){
				cdev_init(&char_dev_array[i], &chardev_fops);
				cdev_add(&char_dev_array[i], dev_array[i], 1);
		}
		printk(KERN_INFO "init cdev_array.\n");
		printk(KERN_INFO "Hello World\n");
		return 0;
}

static void __exit hello_exit(void)
{
		int i = 0;
		//delete chardevice
		for (i = 0; i < BUFFSIZE+1; i++ ){
				cdev_del(&char_dev_array[i]);
		}
		unregister_chrdev_region(dev_array[0], 9);

		printk(KERN_INFO "bye world\n");
		return;
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Yota Nagai");
