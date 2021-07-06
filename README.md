# tedditor
## What is this?
A gtk based simple text editor I'm writing for a school project.

## Can I use it?
No,
The current version is just a mix and match of examples from https://docs.gtk.org/gtk4/getting_started.html. This is currently just [this application here](https://gitlab.gnome.org/GNOME/gtk/-/tree/master/examples/application3 "the GTK4 example application 3"). What I changed is that I put my own text into it, made the font monospaced, put a margin around the text for easier viewing and updated the application id to `com.github.erdragh.tedditor`, to better reflect that this will be my application.
**It also cannot yet be installed.**

## Future plans
In the future this will be a basic text editor. It will be able to open text files, modify them and save them. I will also make an icon that will be a teddybear that writes on something.
You will also be able to open files from the command line with this editor via one or more of these commands:

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

Here is a screenshot of the current state of the application (With the `Vimix` GTK theme):

![vimix](https://github.com/Erdragh/tedditor/raw/main/preview4.png "Screenshot with `Vimix` as the GTK theme")