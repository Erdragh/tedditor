# tedditor
## What is this?
A gtk based simple text editor I'm writing for a school project.

## Can I use it?
No,
The current version is just one of the gtk examples, with the first button, but I put my own text into it and updated the application id to `com.github.erdragh.tedditor`, to better reflect that this will be my application.

## Future plans
The "Open File" button will not be the intended way to open files, rather I will use a menubar with a `File` menu and the usual `Open...`, `Save` and `Save as...`. I also want to implement opening text files from any file explorer or the command line, such as:

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

Here is a screenshot of the current state of the application (With the `Fluent-dark-compact` and the `vimix-dark-laptop-ruby` gtk themes):

![fluent](https://github.com/Erdragh/tedditor/raw/main/tedditor.png "Screenshot with `Fluent-dark-compact`")
![vimix](https://github.com/Erdragh/tedditor/raw/main/tedditor2.png "Screenshot with `vimix-dark-laptop-ruby`")