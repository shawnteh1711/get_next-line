# get_next-line
Piscine 42 get_next_line


## algorithms
1. check whether save_line has '\n' inside. On first run, save_line is null, ft_strchr not return a char and read_bytes is not 0 , so it will go into the while loop to read(). In the while loop, the buffer and save_line will be joined.
2. go to ft_get_line, to get the line while until the '\n'. Memory allocated until i + 2 as '\n' and '\0' is required to be added at the end of line.
3. go to ft_save, to remove the line from save_line in order to get the next read line. save the next line as save_line. if no more next line, function return null.
