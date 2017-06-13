#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>

#define BUFFSIZE 8
#define CHARSIZE 1
#define HELLOSIZE 7

struct cdev char_dev_array[BUFFSIZE+1];
char kern_buff[BUFFSIZE+1] = "hakodate";

char hello_array[BUFFSIZE+1][HELLOSIZE] = {
		"hello0",
		"hello1",
		"hello2",
		"hello3",
		"hello4",
		"hello5",
		"hello6",
		"hello7",
		"hello8"
};

static int chardev_open(struct inode *inode, struct file *file){
		printk(KERN_INFO "Device Opended.\n");
		return 0;
}

static int chardev_close(struct inode *inode, struct file *file){
		printk(KERN_INFO "Device Closed.\n");
		return 0;
}

static ssize_t chardev_read0(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_to_user(buf, &kern_buff[0], CHARSIZE);
		return count;
}

static ssize_t chardev_write0(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_from_user(&kern_buff[0], buf, CHARSIZE);
		return count;
}

static ssize_t chardev_read1(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_to_user(buf, &kern_buff[1], CHARSIZE);
		return count;
}


static ssize_t chardev_write1(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_from_user(&kern_buff[1], buf, CHARSIZE);
		return count;
}

static ssize_t chardev_read2(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_to_user(buf, &kern_buff[2], CHARSIZE);
		return count;
}

static ssize_t chardev_write2(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_from_user(&kern_buff[2], buf, CHARSIZE);
		return count;
}

static ssize_t chardev_read3(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		printk(KERN_INFO "now kern buff is %s\n", kern_buff);
		copy_to_user(buf, &kern_buff[3], CHARSIZE);
		return count;
}


static ssize_t chardev_write3(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_from_user(&kern_buff[3], buf, CHARSIZE);
		return count;
}

static ssize_t chardev_read4(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_to_user(buf, &kern_buff[4], CHARSIZE);
		return count;
}

static ssize_t chardev_write4(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_from_user(&kern_buff[4], buf, CHARSIZE);
		return count;
}

static ssize_t chardev_read5(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_to_user(buf, &kern_buff[5], CHARSIZE);
		return count;
}


static ssize_t chardev_write5(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_from_user(&kern_buff[5], buf, CHARSIZE);
		return count;
}

static ssize_t chardev_read6(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_to_user(buf, &kern_buff[6], CHARSIZE);
		return count;
}

static ssize_t chardev_write6(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_from_user(&kern_buff[6], buf, CHARSIZE);
		return count;
}

static ssize_t chardev_read7(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_to_user(buf, &kern_buff[7], CHARSIZE);
		return count;
}


static ssize_t chardev_write7(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < CHARSIZE) {
				printk(KERN_INFO "error:count size smaller than 1\n");
				return -ENOSPC;
		}
		copy_from_user(&kern_buff[7], buf, CHARSIZE);
		return count;
}

static ssize_t chardev_read8(struct file *file, char __user *buf, size_t count, loff_t *loff){
		if (count < BUFFSIZE) {
				printk(KERN_INFO "error:count size smaller than 8 read\n");
				return -ENOSPC;
		}
		copy_to_user(buf, kern_buff, BUFFSIZE);
		return count;
}


static ssize_t chardev_write8(struct file *file, const char __user *buf, const size_t count, loff_t *loff){
		if (count < BUFFSIZE) {
				printk(KERN_INFO "error:count size smaller than 8 write\n");
				return -ENOSPC;
		}
		copy_from_user(kern_buff, buf, BUFFSIZE);
		return count;
}


static struct file_operations chardev_fops_array[BUFFSIZE+1] = {
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read0,
				.release = chardev_close,
				.write = chardev_write0,
		},
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read1,
				.release = chardev_close,
				.write = chardev_write1,
		},
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read2,
				.release = chardev_close,
				.write = chardev_write2,
		},
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read3,
				.release = chardev_close,
				.write = chardev_write3,
		},
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read4,
				.release = chardev_close,
				.write = chardev_write4,
		},
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read5,
				.release = chardev_close,
				.write = chardev_write5,
		},
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read6,
				.release = chardev_close,
				.write = chardev_write6,
		},
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read7,
				.release = chardev_close,
				.write = chardev_write7,
		},
		{
				.owner = THIS_MODULE,
				.open = chardev_open,
				.read = chardev_read8,
				.release = chardev_close,
				.write = chardev_write8,
		}
};

dev_t dev_array[BUFFSIZE+1];

static int __init hello_init(void)
{
		int i = 0;
		//setup major minor number
		for (i = 0; i < BUFFSIZE+1; i++ ){
				dev_array[i] = MKDEV(240, i);
		}
		for (i = 0; i < BUFFSIZE+1; i++ ){
				register_chrdev_region(dev_array[i], 1, hello_array[i]);
				cdev_init(&char_dev_array[i], &chardev_fops_array[i]);
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
				unregister_chrdev_region(dev_array[i], 1);
		}

		printk(KERN_INFO "bye world\n");
		return;
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Yota Nagai");
