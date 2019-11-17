package tags;

import java.io.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

public class HelloTag extends SimpleTagSupport {
    private String name = null;
    public void setName(String name) {
        this.name = name;
    }
    public void doTag() throws IOException {
        getJspContext().getOut().println("Hello " + name);
    }
}

