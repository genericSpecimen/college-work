<%@ page contentType="text/html" %>
<%@ page import="java.time.LocalTime" %>

<html>
    <body>
        <form action="4_wish-time-of-day.jsp" method="POST">
            <input type="hidden" name="submitted" value="true">
            Enter your name: <input type="text" name="username">
            <input type="submit" value="Submit">
        </form>
        <%
            if(request.getParameter("submitted") != null) {
                String uname = request.getParameter("username");
                LocalTime now = LocalTime.now();
                int hour = now.getHour();
                if(hour < 12) {
                    out.println("<h1>Good Morning " + uname + "!</h1>");
                } else if(hour < 18) {
                    out.println("<h1>Good Afternoon " + uname + "!</h1>");
                } else {
                    out.println("<h1>Good Evening " + uname + "!</h1>");
                }
            }
        %>

    </body>
</html>
