Islandora Solr Facet Pages
==========================

The Islandora Solr facet pages module allows you to browse through solr facet
data through an alphabetically split up navigation interface. You can set
multiple pages for different solr fields to facet on.


Dependencies
------------

islandora_solr_search


Instructions
------------

Navigate to admin/settings/islandora_solr_search/facet_pages for configuration.
Fill out a solr field, title and path to define a page.
The pages are located at /browse/{your-path}


Theming
-------

There are template files for the entire page and the results list. The
alphabetical pager uses a theme function.

Template files can be overridden by a theme by copying the template file from
the modules folder into the theme folder. You can override a theme per defined
facet page by appending the path value to the template file. If you do, make
sure to copy the original template file to your theme as well.
eg:
islandora-solr-facet-pages-results.tpl.php
islandora-solr-facet-pages-results--{your-path}.tpl.php



TODO
====

- add ability to sort by number of results as well.
- add ability to split up results in sections. eg: Aa-Ac, Ad-Ag, Ah-Aj, etc.
- code works great, but OOP might be handier code architecture