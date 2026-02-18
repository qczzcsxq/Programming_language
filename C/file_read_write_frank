//创建临时文件，重新写入内容，然后改为原文件名
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <inttypes.h>
#include <string.h> 
#include <stdbool.h>

#define BUFFER_SIZE 256
errno_t change_config_safe(const char* filename,const char* search_str,const char* replace_str);

int main() {
	const char* filename = "C:\\Users\\33509\\Desktop\\1.txt";
	const char* search_str = "456";
	const char* replace_str = "00000000000";
	errno_t err = change_config_safe(filename, search_str, replace_str);
	
	if (err != 0) {
		puts("Replacement has mistakes.");
		int numclosed = _fcloseall();
		printf("Number of files closed by _fcloseall(): %d\n", numclosed);
		return 0;
	}

	puts("Success!\n");

	int numclosed = _fcloseall();
	printf("Number of files closed by _fcloseall(): %d\n", numclosed);
	return EXIT_SUCCESS;
}

errno_t change_config_safe(const char* filename, const char* search_str, const char* replace_str) {
	if (filename == NULL || search_str == NULL || replace_str == NULL) {
		return EINVAL;   //EINVAL
	}

	char temp_filename[L_tmpnam_s]; //宏 260
	errno_t err = tmpnam_s(temp_filename, L_tmpnam_s);
	if (err != 0) {
		return err;
	}

	FILE* file_ptr = NULL;
	FILE* temp_file_ptr = NULL;

	err = fopen_s(&file_ptr, filename, "r");
	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];
		strerror_s(error_msg, sizeof(error_msg), errno);
		fprintf(stderr, "Failed to open config file for reading:%s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	err = fopen_s(&temp_file_ptr, temp_filename, "w");
	if (err != 0 || temp_file_ptr == NULL) {
		fclose(file_ptr);  //!!!!!十分重要
		return errno;//简写
	}

	char buffer[BUFFER_SIZE];
	int found = 0;

	while (fgets(buffer, BUFFER_SIZE, file_ptr) != NULL) {  //注意 第二项一定不是sizeof(buffer)，buffer没满，replace_set长度可能大于search_str
		if (found == false && strstr(buffer, search_str) != NULL) {
			found = true;
			fprintf(temp_file_ptr, "%s\n", replace_str);

		}
		else {
			fputs(buffer, temp_file_ptr);
		}
	}

	fclose(file_ptr);
	fclose(temp_file_ptr);

	if (found) {
		if (remove(filename) != 0) {   //remove返回0是成功  该操作是删除名为filename的文件，文件名变为可用状态
			remove(temp_filename);
			return errno;  //返回当前错误码
		}
		if (rename(temp_filename, filename) != 0) {
			return errno;
		}
	}
	else {
		remove(temp_filename);
		return ENOENT;  //"entry not found"(in this context)   "No such file or directory"
	}
	return 0;
}
