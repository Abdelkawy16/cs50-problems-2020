select distinct(name) from people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
where title IN(select distinct(movies.title) from movies
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where name = "Kevin Bacon" and birth = 1958) AND people.name != "Kevin Bacon";