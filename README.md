# Islandora Solr Facet Pages [![Build Status](https://travis-ci.org/Islandora/islandora_solr_facet_pages.png?branch=7.x)](https://travis-ci.org/Islandora/islandora_solr_facet_pages)

## Introduction

The Islandora Solr Facet Pages module creates an alphabetical "A to Z" browse from metadata indexed in Solr. The "facets" are the fields that Solr will search in to build the A-to-Z browse. You can set up multiple A-to-Z pages.

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Tuque](https://github.com/islandora/tuque)
* [Islandora Solr Search](https://github.com/Islandora/islandora_solr_search)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

To configure facet pages, set 'Results per page', and 'Maxiumum searchable facet values' go to Administration » Islandora » Solr index » Facet Pages (admin/islandora/search/islandora_solr/facet_pages). The browse pages are located at browse/{your-path}.  In Administration >> Structure >> Blocks there is an Islandora Solr facet pages block available which contains a list of links to all configured facet pages.

![Configuration](https://camo.githubusercontent.com/429ac52fd3f2f34f912b64dec3f6a3f87610e7ad/687474703a2f2f692e696d6775722e636f6d2f736c594e4c65712e706e67)

### Theming

There are template files for the entire page and the results list. The alphabetical pager uses a theme function.

Template files can be overridden by a theme by copying the template file from the modules folder into the theme folder. You can override a theme per defined facet page by appending the path value to the template file. If you do, make sure to copy the original template file to your theme as well.

eg:
islandora-solr-facet-pages-results.tpl.php
islandora-solr-facet-pages-results--{your-path}.tpl.php

## Documentation

Further documentation for this module is available at [our wiki](https://wiki.duraspace.org/display/ISLANDORA/Islandora+Solr+Facet+Pages).

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* [Nelson Hart](https://github.com/nhart)

## Development

If you would like to contribute to this module, please check out [CONTRIBUTING.md](CONTRIBUTING.md). In addition, we have helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the [Islandora.ca](http://islandora.ca) site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
