<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
    <body>
        <form action="input_jstl.jsp" method="POST">
            Name: <input type="text" name="name"> <br>
            Birth Date: <input type="text" name="birthDate"> (Use format yyyy-mm-dd) <br>
            Email Address: <input type="text" name="emailAddr"> (Use format name@company.com) <br>
            Gender: 
                <input type="radio" name="gender" value="m" checked>Male
                <input type="radio" name="gender" value="f">Female <br>
            Lucky number: <input type="text" name="luckyNumber"> (A number between 1 and 100) <br>
            Favorite Foods: <br>
                <input type="checkbox" name="food" value="z">Pizza<br>
                <input type="checkbox" name="food" value="p">Pasta<br>
                <input type="checkbox" name="food" value="c">Chinese <br>
                <input type="submit" value="Send Data">
        </form>
        You entered: <br>
        Name: <c:out value="${param.name}" /> <br>
        birthDate: <c:out value="${param.birthDate}" /> <br>
        emailAddr: <c:out value="${param.emailAddr}" /> <br>
        Gender: <c:out value="${param.gender}" /> <br>
        luckyNumber: <c:out value="${param.luckyNumber}" /> <br>
        Favorite food:
            <c:forEach items="${paramValues.food}" var="current">
                <c:out value="${current}" /> &nbsp;
            </c:forEach>
    </body>
</html>