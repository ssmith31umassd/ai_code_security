<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Employee ID Page</title>
</head>
<body>
    <h1>Employee ID Page</h1>
    
    <%-- Retrieve employee ID from request parameter "eid" --%>
    <% String employeeId = request.getParameter("eid"); %>
    
    <%-- Check if employee ID is not null --%>
    <% if(employeeId != null && !employeeId.isEmpty()) { %>
        <p>Employee ID: <%= employeeId %></p>
    <% } else { %>
        <p>No Employee ID provided.</p>
    <% } %>
</body>
</html>
