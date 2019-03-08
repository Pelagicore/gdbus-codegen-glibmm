How to contribute
=================
We are happy to accept contributions. 

We aim to follow the [GNOME
guidelines](https://wiki.gnome.org/Git/CommitMessages) for commit messages.

gdbus-codegen-glibmm is open source software, see the LICENSE file to
understand what license we use and what this means.

Help wanted
===========
If you don't know what to start with, please check the
[issues](https://github.com/Pelagicore/gdbus-codegen-glibmm/issues).

Way of Working
==============
The suggested workflow is as follows:

* Fork the repo. In most git frontends, that fork will end up at
   ``git@github.com:<username>/gdbus-codegen-glibmm.git``

* Clone the original fork and add a remote for the upstream to the repo ::

    $ git clone git@github.com:<username>/gdbus-codegen-glibmm.git
    $ git remote add upstream git@github.com:Pelagicore/gdbus-codegen-glibmm.git

This will make the fork have ``origin`` as remote name, which we think feels
most natural for most developers, as it is the repository the developer will
typically push to. On the other hand, we recommend to always type the remote
and branch name when pushing, which forces the developer to be more explicit
about their intentions.

* Check out the master branch and make sure it is up to date ::

   $ git checkout master
   $ git pull upstream master

* Do some work, and commit it. ::

   $ touch new_file
   $ git add new_file
   $ git commit -s -m "Add new_file"

* Make sure your branch is up-to-date with master ::

   $ git pull upstream master --rebase

   This is to make sure that any conflicts that exist before pushing are
resolved locally before pushing. It might be the case that there are more
people working on the same code that has a pull request which just got
accepted, which would lead to a conflict in master. Then it is better to
resolve the conflict in the local branch before creating a new pull request. To
keep the git log clear of empty merge commits, we recommend rebasing.

* Push to the forked remote ::

   $ git push origin some_branch_name

* Create a pull request

Make sure authors are notified of the pull request. There are different ways of
handling changes to the pull request. Either any new changes can be added to an
existing commit and force-pushed to the forked repo, or they can be ammended on
top of the existing commit. The pull request will be updated either way.

Whenever reviewers are satisfied with the changes, pull the changes in by
accepting the pull request.
