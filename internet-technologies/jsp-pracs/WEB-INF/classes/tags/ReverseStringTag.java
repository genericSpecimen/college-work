package tags;

import java.io.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

public class ReverseStringTag extends SimpleTagSupport {
    private String input;

    public void setInput(String input) {
        this.input = input;
    }

    public void doTag() throws IOException {
        JspWriter out = getJspContext().getOut();
        String reversed = new StringBuilder(input).reverse().toString();
        out.println("Reversed: " + reversed);
    }
}
