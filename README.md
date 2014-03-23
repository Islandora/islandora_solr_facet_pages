# Islandora Solr Facet Pages

The Islandora Solr facet pages module allows you to browse through solr facet data through an alphabetically split up navigation interface. You can set multiple pages for different solr fields to facet on.

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Tuque](https://github.com/islandora/tuque)
* [Islandora Solr Search](https://github.com/Islandora/islandora_solr_search)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

Configure facet pages, set 'Results per page', and 'Maxiumum searchable facet values' in Administration » Islandora » Solr index » Solr index (admin/islandora/search/islandora_solr/facet_pages). Pages are located at browse/{your-path} and a block is available which contains a list of links to all configured facet pages.

![Configuration](http://i.imgur.com/slYNLeq.png)

### Theming

There are template files for the entire page and the results list. The alphabetical pager uses a theme function.

Template files can be overridden by a theme by copying the template file from the modules folder into the theme folder. You can override a theme per defined facet page by appending the path value to the template file. If you do, make sure to copy the original template file to your theme as well.

eg:
islandora-solr-facet-pages-results.tpl.php
islandora-solr-facet-pages-results--{your-path}.tpl.php

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* [Nick Ruest](https://github.com/ruebot)

## Development

If you would like to contribute to this module, please check out our helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the Islandora.ca site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
