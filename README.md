# tedditor
## What is this?
A gtk based simple text editor I'm writing for a school project.

## Can I use it?
No,
The current version is just an example from https://developer.gnome.org/gtk4/4.0, which introduces the gtk grid, but I put my own text into it and updated the application id to `com.github.erdragh.tedditor`, to better reflect that this will be my application.

## Future plans
The buttons will not be the intended way open or save files and also not how to close the application, rather I will use a menubar with a `File` menu and the usual `Open...`, `Save` and `Save as...` and closing will just be done by the default gtk window decorations. I also want to implement opening text files from any file explorer or the command line, such as:

```bash
[user@linux ~]$ tedditor ./example.txt
```

or

```bash
[user@linux ~]$ teddit ./example.txt
```

or

```bash
[user@linux ~]$ tdt ./example.txt
```

## Current state

Here is a screenshot of the current state of the application (With the `vimix-dark-laptop-ruby` gtk theme):

![vimix](https://github.com/Erdragh/tedditor/raw/main/tedditor.png "Screenshot with `vimix-dark-laptop-ruby`")