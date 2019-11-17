<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
    <c:set var="username" value="${param.username}" scope="session"/>
    <h2> <c:out value="Hello ${sessionScope.username}!"/> </h2>
    <body>
        <form action="10_receipt.jsp" method="POST">
            Please select each item you want to buy: <br>
            <input type="checkbox" name="itemstobuy" value="pizza"> Pizza <br>
            <input type="checkbox" name="itemstobuy" value="jacket"> Jacket <br>
            <input type="checkbox" name="itemstobuy" value="shirt"> Shirt <br>
            <input type="checkbox" name="itemstobuy" value="pant"> Pant <br>
            <input type="checkbox" name="itemstobuy" value="car"> Car <br>
            <input type="submit" value="Submit">
        </form>
    </body>
</html>
