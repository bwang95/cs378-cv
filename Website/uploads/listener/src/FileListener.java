import net.contentobjects.jnotify.JNotify;
import net.contentobjects.jnotify.JNotifyException;
import net.contentobjects.jnotify.JNotifyListener;

import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;

import static net.contentobjects.jnotify.JNotify.*;

/**
 * Created by brian on 4/24/14.
 */
public class FileListener implements JNotifyListener {
    static HashSet<String> acceptedExtensions;
    static String execPath;
    static String indexPath;
    static String lastFile;

    public static void main(String... args) throws JNotifyException, InterruptedException {
        if (args.length <= 1) {
            System.out.println("FileListener <exec path> <indexpath>");
            System.exit(1);
        }
        execPath = args[0];
        indexPath = args[1];
        String[] ext = {"jpg", "png", "jpeg", "bmp"};
        acceptedExtensions = new HashSet<>();
        acceptedExtensions.addAll(Arrays.asList(ext));

        int events = FILE_CREATED | FILE_MODIFIED | FILE_RENAMED;
        JNotify.addWatch(".", events, false, new FileListener());

        while (true) Thread.sleep(10000);
    }

    @Override
    public void fileCreated(int wd, String root, String name) {
        System.out.println("File created: " + name);
        if (acceptedExtensions.contains(getExtension(name)))
            executeImageMatcher(root + "/" + name);
    }

    @Override
    public void fileDeleted(int wd, String root, String name) {
        System.out.println("File deleted: " + name);
    }

    @Override
    public void fileModified(int wd, String root, String name) {
        System.out.println("File modified: " + name);
        if (acceptedExtensions.contains(getExtension(name)))
            executeImageMatcher(root + "/" + name);
    }

    @Override
    public void fileRenamed(int wd, String root, String name, String newName) {
        System.out.println("File renamed: " + name + " -> " + newName);
        if (acceptedExtensions.contains(getExtension(newName)))
            executeImageMatcher(root + "/" + newName);
    }

    public void executeImageMatcher(String img_path) {
        if(img_path.equals(lastFile))
            return;
        try {
            lastFile = img_path;
            System.out.println("Executing " + execPath + " " + img_path + " " + indexPath);
            Runtime.getRuntime().exec(execPath + " " + img_path + " " + indexPath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String getExtension(String name) {
        return name.substring(name.lastIndexOf(".") + 1).toLowerCase();
    }
}
