package tags;

import java.io.*;
import java.util.Date;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

public class TodayTag extends SimpleTagSupport {
    public void doTag() throws IOException {
        JspWriter out=getJspContext().getOut();
        Date date=new Date();
        out.println("Today's date and time is: " + date);
    }
}
