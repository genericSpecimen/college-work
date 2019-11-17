<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
    <head>
        <style>
            .userinfo { display: table;}
            .userinfo p { display: table-row;}
            .userinfo label {display: table-cell;}
            .userinfo input {display: table-cell;}
        </style>
    </head>
    <body>
        <form action="3_validate-user-input.jsp" method="POST">
            <h1>UserInfo</h1>
            <h3>Please enter the following details:</h3>
            <input type="hidden" name="submitted" value="true">
            <div class="userinfo">

                <c:if test="${param.submitted && empty param.userName}">
                    <p style="color: crimson;">Please enter your name!</p>
                </c:if>
                <p>
                    <label for="userName">Name: </label>
                    <input type="text" id="userName" name="userName" value="<c:out value="${param.userName}"/>">
                </p>

                <c:if test="${param.submitted && empty param.dob}">
                    <p style="color: crimson;">Please enter your Date of Birth!</p>
                </c:if>
                <p>
                    <label for="dob">Date of Birth: </label>
                    <input type="date" id="dob" name="dob" value="<c:out value="${param.dob}"/>">
                </p>

                <c:if test="${param.submitted && empty param.email}">
                    <p style="color:crimson">Please enter your email address!</p>
                </c:if>
                <p>
                    <label for="email">Email address: </label>
                    <input type="text" id="email" name="email" value="<c:out value="${param.email}"/>">
                </p>

                <c:if test="${param.submitted && param.gender != 'm' && param.gender != 'f'}">
                    <p style="color: crimson;">Please select your gender!</p>
                </c:if>
                Gender: <br>
                <c:choose>
                    <c:when test="${param.gender == 'f'}">
                        <input type="radio" name="gender" value="f" checked>Female <br>
                        <input type="radio" name="gender" value="m">Male <br>
                    </c:when>
                    <c:otherwise>
                        <input type="radio" name="gender" value="f">Female <br>
                        <input type="radio" name="gender" value="m" checked>Male <br>
                    </c:otherwise>
                </c:choose>

                <c:if test="${param.submitted && (empty param.luckynum || param.luckynum < 1 || param.luckynum > 100)}">
                    <p style="color: crimson;">Please enter a valid lucky number!</p>
                </c:if>
                <p>
                    <label for="luckynum">Lucky number (1-100): </label>
                    <input type="number" id="luckynum" name="luckynum" value="<c:out value="${param.luckynum}"/>">
                </p>

                <c:forEach items="${paramValues.food}" var="i">
                    <c:choose>
                        <c:when test="${i == 'z'}">
                            <c:set var="isPizzaSelected" value="true" />
                        </c:when>
                        <c:when test="${i == 'p'}">
                            <c:set var="isPastaSelected" value="true" />
                        </c:when>
                        <c:when test="${i == 'c'}">
                            <c:set var="isChineseSelected" value="true" />
                        </c:when>
                        <c:otherwise>
                            <c:set var="isInvalidSelection" value="true" />
                        </c:otherwise>
                    </c:choose>
                </c:forEach>

                <c:if test="${isInvalidSelection}">
                    <p style="color:crimson;">Please select only valid food items!</p>
                </c:if>
                Select your favorite foods: <br>
                <input type="checkbox" name="food" value="z" ${isPizzaSelected ? 'checked':'' } >Pizza <br>
                <input type="checkbox" name="food" value="p" ${isPastaSelected ? 'checked':'' } >Pasta <br>
                <input type="checkbox" name="food" value="c" ${isChineseSelected ? 'checked':'' } >Chinese <br>
                <input type="submit" value="Submit"> <input type="reset" value="Reset form">
            </div>
        </form>

        <br><br>

        <h3>You've entered:</h3> <br>
        Name: <c:out value="${param.userName}" /> <br>
        Date of birth: <c:out value="${param.dob}" /> <br>
        Email address: <c:out value="${param.email}" /> <br>
        Gender: <c:out value="${param.gender}" /> <br>
        Lucky number: <c:out value="${param.luckynum}" /> <br>
        Favorite food:
        <c:forEach items="${paramValues.food}" var="i">
            <c:out value="${i}" /> &nbsp;
        </c:forEach>

    </body>
</html>